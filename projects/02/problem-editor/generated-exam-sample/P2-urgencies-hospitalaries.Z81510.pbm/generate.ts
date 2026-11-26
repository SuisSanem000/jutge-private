#!/usr/bin/env bun

declare function require(name: string): any;
const { writeFileSync } = require("fs");

type SimEvent = { type: "arriba"; id: string; prioritat: number; timestamp: number } | { type: "seguent"; timestamp: number };
type Pacient = { id: string; prioritat: number; timestamp: number };

class Rng {
    private state: number;

    constructor(seed: number) {
        this.state = seed >>> 0;
    }

    int(min: number, max: number): number {
        this.state = (1664525 * this.state + 1013904223) >>> 0;
        return min + (this.state % (max - min + 1));
    }
}

const eventToString = (e: SimEvent): string => {
    if (e.type === "arriba") return `arriba ${e.id} ${e.prioritat} ${e.timestamp}`;
    return `seguent ${e.timestamp}`;
};

const withLeadingZeros = (x: number, width: number): string => {
    const s = String(x);
    if (s.length >= width) return s;
    let zeros = "";
    for (let i = 0; i < width - s.length; i++) zeros += "0";
    return zeros + s;
};

class SimuladorUrgencies {
    private events: SimEvent[] = [];
    private cua: Pacient[] = [];
    private timestamp = 0;
    private numPacients = 0;
    private readonly rng: Rng;
    private readonly prefixId: string;

    constructor(seed: number, prefixId: string = "P") {
        this.rng = new Rng(seed);
        this.prefixId = prefixId;
    }

    private millorPacientIndex(): number {
        let best = 0;
        for (let i = 1; i < this.cua.length; i++) {
            const a = this.cua[i];
            const b = this.cua[best];
            if (a.prioritat < b.prioritat || (a.prioritat === b.prioritat && a.timestamp < b.timestamp)) {
                best = i;
            }
        }
        return best;
    }

    avancaTemps(maxSalt: number): void {
        this.timestamp += this.rng.int(1, maxSalt);
    }

    arriba(prioritat: number): void {
        this.numPacients++;
        const id = `${this.prefixId}${withLeadingZeros(this.numPacients, 5)}`;
        const p: Pacient = { id, prioritat, timestamp: this.timestamp };
        this.cua.push(p);
        this.events.push({ type: "arriba", id, prioritat, timestamp: this.timestamp });
    }

    seguent(): void {
        if (this.cua.length === 0) {
            throw new Error("Event 'seguent' invàlid: cua buida.");
        }
        const i = this.millorPacientIndex();
        this.cua.splice(i, 1);
        this.events.push({ type: "seguent", timestamp: this.timestamp });
    }

    tamanyCua(): number {
        return this.cua.length;
    }

    rndInt(min: number, max: number): number {
        return this.rng.int(min, max);
    }

    getEvents(): SimEvent[] {
        return this.events;
    }
}

const escriu = (nomFitxer: string, events: SimEvent[]) => {
    writeFileSync(nomFitxer, events.map(eventToString).join("\n") + "\n");
};

const generaIntercalat = (
    numPacients: number,
    maxRafegaArribades: number,
    maxSaltArriba: number,
    maxSaltSeguent: number,
    probFerSeguent: number,
    seed: number,
    prefixId: string = "P",
): SimEvent[] => {
    const sim = new SimuladorUrgencies(seed, prefixId);
    let creats = 0;

    while (creats < numPacients || sim.tamanyCua() > 0) {
        const potArribar = creats < numPacients;
        const potFerSeguent = sim.tamanyCua() > 0;

        if (!potFerSeguent || (potArribar && sim.tamanyCua() < 2)) {
            const rafega = Math.min(numPacients - creats, sim.rndInt(1, maxRafegaArribades));
            for (let i = 0; i < rafega; i++) {
                sim.avancaTemps(maxSaltArriba);
                sim.arriba(sim.rndInt(1, 3));
                creats++;
            }
            continue;
        }

        if (potArribar && sim.rndInt(1, probFerSeguent) !== 1) {
            sim.avancaTemps(maxSaltArriba);
            sim.arriba(sim.rndInt(1, 3));
            creats++;
        } else {
            sim.avancaTemps(maxSaltSeguent);
            sim.seguent();
        }
    }

    return sim.getEvents();
};

const generaMateixaPrioritat = (
    numPacients: number,
    prioritat: number,
    maxSaltArriba: number,
    maxSaltSeguent: number,
    seed: number,
    prefixId: string,
): SimEvent[] => {
    const sim = new SimuladorUrgencies(seed, prefixId);
    for (let i = 0; i < numPacients; i++) {
        sim.avancaTemps(maxSaltArriba);
        sim.arriba(prioritat);
    }
    while (sim.tamanyCua() > 0) {
        sim.avancaTemps(maxSaltSeguent);
        sim.seguent();
    }
    return sim.getEvents();
};

const generaPrivate1Petit = (nomFitxer: string, numPacients: number, seed: number) => {
    escriu(nomFitxer, generaIntercalat(numPacients, 2, 3, 4, 2, seed, "A"));
};

const generaPrivate2Petit2 = (nomFitxer: string, numPacients: number, seed: number) => {
    escriu(nomFitxer, generaIntercalat(numPacients, 3, 4, 5, 2, seed, "B"));
};

const generaPrivate3Mitja = (nomFitxer: string, numPacients: number, seed: number) => {
    escriu(nomFitxer, generaIntercalat(numPacients, 4, 5, 7, 3, seed, "C"));
};

const generaPrivate4Mitja2 = (nomFitxer: string, numPacients: number, seed: number) => {
    escriu(nomFitxer, generaIntercalat(numPacients, 5, 6, 8, 3, seed, "D"));
};

const generaPrivate5Gran = (nomFitxer: string, numPacients: number, seed: number) => {
    escriu(nomFitxer, generaIntercalat(numPacients, 8, 8, 12, 4, seed, "E"));
};

const generaPrivate6Gran2 = (nomFitxer: string, numPacients: number, seed: number) => {
    escriu(nomFitxer, generaIntercalat(numPacients, 10, 9, 14, 5, seed, "F"));
};

const generaPrivate7TotsP1 = (nomFitxer: string, numPacients: number, seed: number) => {
    escriu(nomFitxer, generaMateixaPrioritat(numPacients, 1, 4, 6, seed, "G"));
};

const generaPrivate8TotsP3 = (nomFitxer: string, numPacients: number, seed: number) => {
    escriu(nomFitxer, generaMateixaPrioritat(numPacients, 3, 4, 6, seed, "H"));
};

const generaPrivate9Gran3 = (nomFitxer: string, numPacients: number, seed: number) => {
    escriu(nomFitxer, generaIntercalat(numPacients, 12, 10, 16, 5, seed, "I"));
};

const generaPrivate10Gran4 = (nomFitxer: string, numPacients: number, seed: number) => {
    escriu(nomFitxer, generaIntercalat(numPacients, 14, 12, 18, 6, seed, "J"));
};

generaPrivate1Petit("private-1-petit.inp", 6, 101);
generaPrivate2Petit2("private-2-petit2.inp", 12, 102);
generaPrivate3Mitja("private-3-mitja.inp", 40, 103);
generaPrivate4Mitja2("private-4-mitja2.inp", 140, 104);
generaPrivate5Gran("private-5-gran.inp", 400, 105);
generaPrivate6Gran2("private-6-gran2.inp", 1200, 106);
generaPrivate7TotsP1("private-7-tots-p1.inp", 120, 107);
generaPrivate8TotsP3("private-8-tots-p3.inp", 120, 108);
generaPrivate9Gran3("private-9-gran3.inp", 2400, 109);
generaPrivate10Gran4("private-10-gran4.inp", 4800, 110);

console.log("Generats 10 jocs de prova sense events 'surt'.");

const randomDigit = () => Math.floor(Math.random() * 9.95); // slight bias... ;)

const randInt = (from: number, to: number) =>
  Math.floor(Math.random() * (to - from) + from);

const randomCardNumber = () =>
  Array.from({ length: 4 })
    .map(() => randInt(0, 9999).toString().padStart(4, "0"))
    .join("-");

const generateDates = (numDates: number, lastDate: Date) => {
  const dates: Date[] = [lastDate];
  let daysBack = 0;
  for (let i = 0; i < numDates; i++) {
    const d = new Date(lastDate);
    daysBack += randInt(5, 40);
    d.setDate(d.getDate() - daysBack);
    dates.unshift(d);
  }
  return dates;
};

type CardEvent = {
  cardNumber: string;
  date: Date;
  amount: number;
};

const generateCardEvents = (count: number, amount: number, lastDate: Date) => {
  const cardNumber = randomCardNumber();
  const events: CardEvent[] = [];
  const dates: Date[] = generateDates(count, lastDate);
  let totalWeight = 0.0;
  for (const date of dates) {
    const weight = Math.random();
    totalWeight += weight;
    events.push({ cardNumber, amount: weight, date });
  }
  for (const ev of events) {
    ev.amount = Number(((amount * ev.amount) / totalWeight).toFixed(2));
  }
  return events;
};

const MIN_COUNT = 3;
const MIN_AMOUNT = 200.0;
const MIN_LAST_DATE = new Date(2024, 2, 1); // 2024 - *03* - 01

const pad = (n: number, d: number) => n.toString().padStart(d, "0");
const formatDate = (d: Date) =>
  `${pad(d.getFullYear(), 4)}${pad(d.getMonth() + 1, 2)}${pad(d.getDate(), 2)}`;

const generateFile = (filename: string, numCards: number, numCandidates: number) => {
  const events: CardEvent[] = [];
  for (let i = 0; i < numCards; i++) {
    if (i >= numCandidates) {
      const lastDate = new Date(MIN_LAST_DATE);
      lastDate.setDate(lastDate.getDate() - randInt(1, 10));
      events.push(
        ...generateCardEvents(
          randInt(1, MIN_COUNT - 1),
          MIN_AMOUNT * 0.9 * Math.random(),
          MIN_LAST_DATE
        )
      );
    } else {
      const lastDate = new Date(MIN_LAST_DATE);
      lastDate.setDate(lastDate.getDate() + randInt(2, 14));
      events.push(
        ...generateCardEvents(
          randInt(MIN_COUNT, MIN_COUNT + 2),
          MIN_AMOUNT * (1.1 + 0.5 * Math.random()),
          lastDate
        )
      );
    }
  }
  events.sort((a, b) => a.date.getTime() - b.date.getTime());
  Bun.write(
    filename,
    events.map((e) => `${formatDate(e.date)} ${e.cardNumber} ${e.amount}\n`).join("")
  );
};

generateFile("sample1.inp", 2, 0);
generateFile("sample2.inp", 4, 3);
generateFile("private1.inp", 1000, 20);
generateFile("private2.inp", 10000, 200);

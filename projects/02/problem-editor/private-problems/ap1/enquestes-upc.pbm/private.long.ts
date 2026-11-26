// Generate big private test
const NUM_ANSWERS = 20;
const NUM_SURVEYS = 200000;
const NUM_SUBJECTS = 500;

const randint = (n: number) => Math.floor(Math.random() * n);
const randint2 = (begin: number, end: number) => begin + randint(end - begin);

const subjectCodes = Array.from({ length: NUM_SUBJECTS }).map((_) =>
  randint2(100000, 999999)
);

const randomSubject = () => subjectCodes[randint(subjectCodes.length)];

const randomSurvey = (n: number) => {
  const r = () => randint2(1, 6);
  return Array.from({ length: n }).map(() => r());
};

const file = Bun.file(`private.long.inp`);
const writer = file.writer();

writer.write(`${NUM_ANSWERS}\n`);
writer.write(`${NUM_SURVEYS}\n`);
for (let i = 0; i < NUM_SURVEYS; i++) {
  const subject = randomSubject();
  const survey = randomSurvey(NUM_ANSWERS);
  writer.write(`${subject} ${survey.join(` `)}\n`);
}
writer.end();

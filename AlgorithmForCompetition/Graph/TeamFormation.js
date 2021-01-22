// 풀이 시간 20 => 21:48 - 22:08

const N = 7;
const M = 8;

const cmd = [
  [0,1,3],
  [1,1,7],
  [0,7,6],
  [1,7,1],
  [0,3,7],
  [0,4,2],
  [0,1,1],
  [1,1,1]
];

//-----------------------------[input]

const students = [];

for(let i=0;i<N+1;i++) {
  students.push(i);
}

for(let [c, a, b] of cmd) {
  if(c === 1) {
    checkParent(students,a) === checkParent(students,b) ? console.log('YES') : console.log('NO');
  } else {
    makeTeam(students,a,b);
  }
}

function makeTeam(students, a, b) {
  
  const parentA = checkParent(students,a);
  const parentB = checkParent(students,b);

  if(parentA !== parentB) {
    if(parentA > parentB) {
      students[a] = parentB;
    } else {
      students[b] = parentB;
    }
  }
}

function checkParent(students, student) {
  
  if(students[student] !== student) {
    students[student] = checkParent(students,students[student]);
  }

  return students[student];
}




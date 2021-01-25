// 풀이 시간 20 => 13:55 - 14:15

const N = 12;
const students = [
  ["Junkyu", 50, 60, 100], ["Sangkeun", 80, 60, 50], ["Sunyoung", 80, 70, 100], ["Soong", 50, 60, 90],
  ["Haebin", 50, 60, 100], ["Kangsoo", 60, 80, 100], ["Donghyuk", 80, 60, 100], ["Sei", 70, 70, 70],
  ["Wonseob", 70, 70, 90], ["Sanghyun", 70, 70, 80], ["nsj", 80, 80, 80], ["Taewhan", 50, 60, 90]
];

let test = ['aaa','bbb','aab','aac'];

//-----------------------------[input]

students.sort(compString);

students.forEach(student => {
  console.log(student[0]);
})

function compString(a,b) {

  if(a[1] === b[1]) {
    if(a[2] === b[2]) {
      if(a[3] === b[3]) {
        
        if(a[0] > b[0]) return 1;
        else if(a[0] < b[0]) return -1;
        else return 0;

      } else {
        return b[3] - a[3];
      }
    } else {
      return a[2] - b[2];
    }
  } else {
    return b[1] - a[1];
  }
}

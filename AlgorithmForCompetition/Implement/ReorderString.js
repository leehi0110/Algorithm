// 풀이 시간 20 => 12:35 - 12:55

// const string = "K1KA5CB7";
const string = "AJKDLSI412K4JSJ9D";

//-----------------------------[input]

let char = [];
let sum = 0;

for(let c of string) {
  if(isNaN(c)) char.push(c);
  else {
    sum += parseInt(c);
  }
}

console.log(char.sort().join('') + sum.toString());
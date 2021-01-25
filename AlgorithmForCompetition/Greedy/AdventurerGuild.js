// 풀이 시간 30 => 12:11 - 12:41

const N = 5;
const guild = [2,3,1,2,2];
// const guild = [8,1,1,1,1,1,1,1];
// const guild = [2,3,3];
//-----------------------------[input]

let group = 0;
let count = 0;
guild.sort((a,b) => a-b);

for(let i of guild) {
  count += 1;
  if(count >= i) {
    group++;
    count = 0;
  }
}

console.log(group);



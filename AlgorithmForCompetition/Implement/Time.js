const N = 5;

//-----------------------------[input]

const targetTime = (N+1)*3600;
// 1분 60초
// 1시간 3600초
let cnt = 0;

for(let i=0;i<targetTime;i++) {
  let time = [];
  let temp = i;
  time.push(parseInt(parseInt(temp/3600)/10));
  time.push(parseInt(temp/3600)%10);

  temp %= 3600;

  time.push(parseInt(parseInt(temp/60)/10));
  time.push(parseInt(temp/60)%10);

  temp %= 60;

  time.push(parseInt(temp/10));
  time.push(temp%10);

  if(time.includes(3)) cnt ++;
}

console.log(cnt);



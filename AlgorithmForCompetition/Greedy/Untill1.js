const N = 25;
const K = 5;

// -----------------------------[input]

let temp = N;
let cnt = 0;

while(temp !== 1) {
  if(temp%K === 0) temp = Math.floor(temp/K);
  else temp -= 1;
  
  cnt ++;
}

console.log(cnt);




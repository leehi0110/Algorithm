// 풀이 시간 40 => 12:50 - 13:30

const N = 4;
const need = 6;
const arr = [19,15,10,17];

//-----------------------------[input]

arr.sort((a,b) => a-b);

let start = arr[0];
let end = arr[N-1];
let mid;

while(1) {
  mid = parseInt((start+end)/2);
  let sum = 0
  for(let i=0;i<N;i++) {
    arr[i] - mid < 0 ? sum += 0 : sum += arr[i]-mid;
  }

  if(sum === need) break;
  else {
    sum > need ? start = mid+1 : end = mid-1;
  }
}

console.log(mid);
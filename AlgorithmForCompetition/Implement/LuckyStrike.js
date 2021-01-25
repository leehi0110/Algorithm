// 풀이 시간 20 => 12:43 - 13:03

const score = 123402;
// const score = 7755;

//-----------------------------[input]

const arr = score.toString().split('');
let leftSum = rightSum = 0;
let i = 0;
let j = arr.length-1;

while(i < j) {
  leftSum += parseInt(arr[i]);
  rightSum += parseInt(arr[j]);

  i++;
  j--;
}

console.log(leftSum === rightSum ? 'LUCKY' : 'READY' );

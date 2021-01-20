// 풀이 시간 30분 => 12:35 - 13:05

const N = 5;
const have = [8,3,7,9,2];
const M = 3;
const need = [5,7,9];

//-----------------------------[input]

// binarySearch를 이용한 풀이

have.sort((a,b) => a-b);

for(let i=0;i<M;i++) {
  const target = need[i];
  console.log(findItem(have,0,N-1,target));
}

function findItem (arr, start, end, target) {
  while(start <= end) {
    mid = parseInt((start+end)/2);
    
    if(arr[mid] === target) {
      return 'Yes';
    } else if(arr[mid] < target) {
      start = mid + 1;
    } else end = mid - 1;
  }

  return 'No';
}

// binarySearch가 아닌 includes()를 사용한 풀이

// for(let i=0;i<M;i++) {
//   if(have.includes(need[i])) console.log('yes');
//   else console.log('no');
// }

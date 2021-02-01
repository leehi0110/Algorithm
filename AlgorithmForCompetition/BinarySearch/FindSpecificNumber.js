// 풀이 시간 30 => 19:06 - 19:36

const N = 7;
const X = 2;
const arr = [1,1,2,2,2,2,3];

// const N = 7;
// const X = 4;
// const arr = [1,1,2,2,2,2,3];

//-----------------------------[input]

const newArr = arr.filter(ele => ele === X);

newArr.length === 0 ? console.log(-1) : console.log(newArr.length);


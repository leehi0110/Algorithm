let firstInput = [[3,1,2],[4,1,4],[2,2,2]];
let secondInput = [[7,3,1,8],[3,3,3,4]];

//-----------------------------[input]

let min = 0;

for(let i=0;i<secondInput.length;i++) {
  const minNum = Math.min.apply(null,secondInput[i]);
  
  if(minNum > min) min = minNum;
}

console.log(min);

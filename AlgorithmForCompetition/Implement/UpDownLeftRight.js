const N = 5;
const MAP = ['R','R','R','U','D','D'];

//-----------------------------[input]

let x = 0;
let y = 0;
const rangeX = [0,N-1];
const rangeY = [0,N-1];

for(const direction of MAP) {

  if(direction === 'R') {
    if(x < rangeX[1]) x++;
  } else if(direction === 'L') {
    if(x > rangeX[0]) x--;
  } else if(direction == 'D') {
    if(y < rangeY[1]) y++;
  } else {
    if(y > rangeY[0]) y--;
  }  
}

console.log(y+1,x+1);

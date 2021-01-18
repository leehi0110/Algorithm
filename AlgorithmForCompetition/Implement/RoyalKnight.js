const place = 'a1';

//-----------------------------[input]

const placeNumber = [parseInt(place[1]), place.charCodeAt(0) - 96];
const direction = [[-2,-1], [-2,1], [2,-1], [2,1], [-1,2], [1,2],[-1,-2],[1,-2]];
let cnt = 0;

for(let i=0;i<direction.length;i++) {
  if(direction[i][0] + placeNumber[0] >= 1 && direction[i][1] + placeNumber[1] >=1) cnt ++;
}

console.log(cnt);
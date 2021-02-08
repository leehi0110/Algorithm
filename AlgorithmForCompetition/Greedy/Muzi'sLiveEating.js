// 풀이 시간 30 => 13:45 - 15:15
// https://programmers.co.kr/learn/courses/30/lessons/42891

function solution(food_times, k) {
  let foods = food_times.map((ele,idx) => {
      return {'index': idx+1, 'time': ele}
  }).sort((a,b) => a.time - b.time);
  
  for(let i=0;i<foods.length;i++) {
      let len = foods.length - i;
      let eatingTime = (foods[i].time - (i === 0 ? 0 : foods[i-1].time))*len;
      
      if(k < eatingTime) {
          return foods.slice(i).sort((a,b) => a.index - b.index)[k%len].index;
      }
      
      k -= eatingTime;
  }
  return -1;
}


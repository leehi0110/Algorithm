function solution(genres, plays) {
  var answer = [];
  let sortCnt = [];
  let musicArr = [];
  let cntObj = {};

  for(let i=0;i<genres.length;i++) {
    const genre = genres[i];
    const count = plays[i];

    if(genre in cntObj) {
      cntObj[genre] += count;
    } else cntObj[genre] = count;

    musicArr.push([i,genre,count]);
  }

  for(let item in cntObj) {
    sortCnt.push([item,cntObj[item]]);
  }

  musicArr.sort((a,b) => b[2] - a[2]);
  sortCnt.sort((a,b) => b[1] - a[1]);

  for(let item of sortCnt) {
    const temp = musicArr.filter(music => music[1] === item[0]);
    if(temp.length === 1) answer.push(temp[0][0]);
    else {
      answer.push(temp[0][0]);
      answer.push(temp[1][0]);
    }
  }
  return answer;
}
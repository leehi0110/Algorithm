function solution(s) {
    
  let min = 99999;

    if(s.length === 1) return 1;
  
  for(let i=1;i<=Math.floor(s.length/2);i++) {
      let temp = [];
      let tempStr = '';
      let cnt = 1;
      
      for(let j=0;j<s.length;j+=i) {
          temp.push(s.substr(j,i));
      }
      
      let prevChar = temp[0];
      for(let j=1;j<temp.length;j++) {
          let nowChar = temp[j];
          if(prevChar !== nowChar) {
              if(cnt === 1) {
                  tempStr += prevChar;
              } else {
                  tempStr += (cnt.toString() + prevChar);
              }
              prevChar = nowChar;
              cnt = 1;
          } else {
            cnt ++;
          }

          if(j === temp.length-1) {
              if(cnt === 1) {
                  tempStr += prevChar;
              } else {
                  tempStr += (cnt.toString() + prevChar);
              }
          }
      }
      if(min > tempStr.length) min = tempStr.length;
  }   
  return min;
}
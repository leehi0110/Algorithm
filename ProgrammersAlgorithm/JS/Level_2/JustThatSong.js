function solution(m, musicinfos) {
  var answer = '';
  const musicInfo = {};

  for(let music of musicinfos) {
    const [startTimes, endTimes, name, original] = music.split(',');
    const replace = original.replace('#','Z');
    const duration = checkDuration(startTimes, endTimes);
    let index = 0;
    let repeat = "";

    if(duration > original.length) {
    
      for(let i=0;i<duration;i++) {
        if(replace[index] === 'Z') {
          i--;
        }
        repeat += replace[index];
        index++;
        if(index === original.length) index = 0;
      }
    } else repeat = replace;

    musicInfo[name] = [duration,repeat];
  }

  console.log(musicInfo);

  return answer;
}

function checkDuration(startTimes, endTimes) {
  const startTime = startTimes.split(':');
  const endTime = endTimes.split(':');

  return (parseInt(endTime[0]) - parseInt(startTime[0]))*60 + parseInt(endTime[1]) - parseInt(startTime[1]);
}
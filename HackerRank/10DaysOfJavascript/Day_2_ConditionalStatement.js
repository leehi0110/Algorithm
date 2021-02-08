function getGrade(score) {
  let grade;
  
  if(score >25 && score <= 30) grade = 'A';
  else if(score > 20 && score <= 25) grade = 'B';
  else if(score > 15 && score <= 20) grade = 'C';
  else if(score > 10 && score <= 15) grade = 'D';
  else if(score > 5 && score <= 10) grade = 'E';
  else grade = 'F'
  
  return grade;
}

function getLetter(s) {
  let checkLetter = s[0];
  
  switch(checkLetter) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
          return 'A';
      case 'b':
      case 'c':
      case 'd':
      case 'f':
      case 'g':
          return 'B';
      case 'h':
      case 'j':
      case 'k':
      case 'l':
      case 'm':
          return 'C';
      default:
          return 'D';
  }
}
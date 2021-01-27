function solution(expression) {
  let number = [];
  let oper = [];
  var answer = 0;

  const operCase = [['+','-','*'],['+','*','-'],['*','+','-'],['*','-','+'],['-','+','*'],['-','*','+']];

  number = expression.split(/[*+-]/);
  oper = expression.split(/[0-9]/).filter(char => {
    if(char === '+' || char === '-' || char === '*') return true;
    else return false;
  });

  for(let i=0;i<openCase.length;i++) {
    let tempNumber = number;
    let tempOper = oper;
    let pri = 0;

    while(tempNumber.length !== 1) {
      let index = tempOper.indexOf(operCase[i][pri]);
      if(index !== -1) {
      } else pri++;
    }
  }

  return answer;
}
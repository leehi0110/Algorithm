// function solution(files) {
//   var answer = [];
//   var sortArr = [];
  
//   for(let i=0;i<files.length;i++) {
//     const file = files[i];
//     answer.push(splitFile(file));
//   }

//   answer.sort((a,b) => {
//     if(a[0].toUpperCase() > b[0].toUpperCase()) return 1;
//     else if(a[0].toUpperCase < b[0].toUpperCase()) return -1;
//     else return 0;
//     // return a[2].toUpperCase() > b[2].toUpperCase();
//   });
//   // answer.sort((a,b) => {
//   //   if(a[0].toUpperCase() === b[0].toUpperCase()) {
//   //     if(parseInt(a[1]) === parseInt(b[1])) {
//   //       if(a[2].toUpperCase < b[2].toUpperCase) return true;
//   //       else return false;
//   //     } else return parseInt(a[1])- parseInt(b[1]);
//   //   } else if(a[0].toUpperCase > b[0].toUpperCase) return false;
//   //   else return true;
//   // });

//   for(let splitItem of answer) {
//     sortArr.push(splitItem.join(''));
//   }

//   return sortArr;
// }

// function splitFile(file) {
//   let returnArr = [];
//   let tempStr = '';
//   let fileChar;
//   let part = 'head';

//   for(let i=0;i<file.length;i++) {
//     fileChar = file[i];

//     if(part === 'head') {
//       if(fileChar >= '0' && fileChar <= '9') {
//         returnArr.push(tempStr);
//         tempStr = fileChar;
//         part = 'number';
//       } else {
//         tempStr += fileChar;
//       }
//     } else if(part === 'number') {
//       if(fileChar >= '0' && fileChar <= '9') {
//         tempStr += fileChar;
//       } else {
//         returnArr.push(tempStr);
//         tempStr = fileChar;
//         part = 'tail';
//       }
//     } else { // part === 'tail'
//       tempStr += fileChar;
//     }

//     if(file.length -1 === i) returnArr.push(tempStr);
//   }

//   console.log(returnArr);
//   return returnArr;
// }

let arr = ['C-','B','B-','A-'];
arr.sort((a,b) => {
  if(a > b) return 1;
  else if(a < b) return -1;
  else return 0;
});

console.log(arr);
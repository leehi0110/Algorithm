const student = [['홍길동', 95], ['이순신', 77]];

//-----------------------------[input]

const sortResult = student.sort((a,b) => a[1] - b[1]);

sortResult.forEach(stud => console.log(stud[0]));

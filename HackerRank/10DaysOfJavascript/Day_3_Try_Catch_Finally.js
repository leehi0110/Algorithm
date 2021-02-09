function reverseString(s) {
  try {
      let splitString = s.split('').reverse().join('');
      console.log(splitString);
  }
  catch(e) {
      console.log(e.message);
      console.log(s);
  }
}
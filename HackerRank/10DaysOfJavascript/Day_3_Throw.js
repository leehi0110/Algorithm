function isPositive(a) {
  if(a > 0) {
      return "YES";
  } else if(a === 0) {
      throw new Error("Zero Error");
      // let error = new Error("Zero Error");
      // return error.message;
  } else {
      throw new Error("Negative Error");
      // let error = new Error('Negative Error');
      // return error.message;
  }
}
class Polygon {
  constructor(arr) {
    this.sides = arr;
  }

  perimeter() {
    let result = 0;
    for (let side of this.sides) {
      result += side;
    }
    return result;
  }
}

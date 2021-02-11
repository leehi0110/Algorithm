function modifyArray(nums) {
  return nums.map((number) => {
    return number % 2 === 0 ? number * 2 : number * 3;
  });
}

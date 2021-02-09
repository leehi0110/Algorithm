function getSecondLargest(nums) {
  // let uniqueNum = nums.filter((ele,idx) => {
  //     return nums.indexOf(ele) === idx;
  // });
  let setNum = new Set(nums);
  let uniqueNum = [...setNum];

  let max = Math.max(...uniqueNum);
  uniqueNum.splice(uniqueNum.indexOf(max), 1);
  return Math.max(...uniqueNum);
}

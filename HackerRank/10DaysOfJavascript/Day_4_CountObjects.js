function getCount(objects) {
  let cnt = 0;

  for (let i = 0; i < objects.length; i++) {
    if (objects[i].x === objects[i].y) cnt++;
  }

  return cnt;
}

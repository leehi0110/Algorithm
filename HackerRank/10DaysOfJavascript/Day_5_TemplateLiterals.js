function sides(literals, ...expressions) {
  const [a, p] = expressions;
  let s1, s2;

  s1 = (p + Math.sqrt(Math.pow(p, 2) - 16 * a)) / 4;
  s2 = (p - Math.sqrt(Math.pow(p, 2) - 16 * a)) / 4;

  return [s1, s2].sort((a, b) => a - b);
}

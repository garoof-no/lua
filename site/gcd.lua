local function gcd(a, b) return b == 0 and a or gcd(b, a % b) end

return {
  gcd = gcd
}


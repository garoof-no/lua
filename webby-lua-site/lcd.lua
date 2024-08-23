local gcd = require("gcd")
local math = require("math")

local function lcd(a, b) return math.abs(a * b) / gcd.gcd(a, b) end

return {
  lcd = lcd
}


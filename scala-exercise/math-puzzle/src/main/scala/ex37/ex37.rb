def next_dice(dice)
  right = dice.slice!(0..(dice[0].to_i - 1)).tr('123456', '654321')
  dice += right
end

count = 0
(6 ** 6).times do |i|
  dice = (i.to_s(6).to_i + 111111).to_s
  check = Hash.new
  j = 0

  while !check.has_key?(dice) do
    check[dice] = j
    dice = next_dice(dice)
    j += 1
  end

  count += 1 if check[dice] > 0
end

puts count

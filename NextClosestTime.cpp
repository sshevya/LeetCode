
Page Link = "https://aaronice.gitbook.io/lintcode/string/next-closest-time"
  

This approach here is trying to find next digit for each postion in "HH:MM" from right to left. If the next digit is greater than current digit, return directly and keep other digits unchanged.
Here is the steps: (e.g."17:38")
Retrieve all four digits from given string and sort them in asscending order,"17:38"->digits[] {'1', '3', '7', '8'}
ApplyfindNext()from the right most digit to left most digit, try to find next greater digit fromdigits[](if exist) which is suitable for current position, otherwise return the minimum digit (digits[0]):
"HH:M_": there is no upperLimit for this position (0-9). Just pick the next different digit in the sequence. In the example above,'8'is already the greatest one, so we change it into the smallest one (digits[0]i.e.'1') and move to next step:"17:38" -> "17:31"
"HH:_M": the upperLimit is'5'(00~59). The next different digit for'3'is'7', which is greater than'5', so we should omit it and try next. Similarly,'8'is beyond the limit, so we should choose next, i.e.'1':"17:38" -> "17:11"
"H_:MM": the upperLimit depends onresult[0]. Ifresult[0] == '2', then it should be no more than'3'; else no upperLimit (0-9). Here we haveresult[0]='1', so we could choose any digit we want. The next digit for'7'is'8', so we change it and return the result directly."17:38" -> "18:11"
"_H:MM": the upperLimit is'2'(00~23). e.g."03:33" -> "00:00"

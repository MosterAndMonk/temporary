def isNumeric(s):
    # write code here
    import re
    return re.match(r"^(([\\+-]?[0-9]+)|([\\+-]?[0-9]*(\\.)[0-9]+)|([\\+-]?[0-9]+[eE][\\+-]?[0-9]+)|([\\+-]?[0-9]*(\\.)[0-9]+[eE][\\+-]?[0-9]+))$", s)
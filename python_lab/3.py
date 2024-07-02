agencies = {'cbi':'central beuro of investigation','fbi':'federal day ini','nia':'nation inainnt','ssb':'sesional ska baid','wap':'wajk aka la'}
print(agencies)
agencies['bse']='bombay stack es'
del agencies['fbi']
print(agencies)
qq = agencies.get('fbi','not found')
print(qq)
 #alien_0 = {'color': 'green', 'speed': 'slow'}
#  print(alien_0['points'])
#  This results in a traceback, showing a KeyError:
#  Traceback (most recent call last):
#   File "alien_no_points.py", line 2, in <module>
#     print(alien_0['points'])
#           ~~~~~~~^^^^^^^^^^
#  KeyError: 'points'

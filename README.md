# DinoGenerator
This is the first laboratory work.
---
## 5 вариант.

В задании не говорилось про создание клиента, но пока смотрела курс на stepik создала и решила с ним оставить. Без него все тоже работает.

### ПОРЯДОК БЕЗ КЛИЕНТА: 

_1 терминал:_

roscore


_2 терминал:_

catkin_make

source devel/setup.bash

rosrun dino_package dino_server


_3 терминал (топик):_

rostopic echo /dino_topic


_4 терминал (сервис):_

source devel/setup.bash

rosservice call /dino_service "dino_begin: 'YOUR WORD '"



### ПОРЯДОК С КЛИЕНТОМ: 

_1 терминал:_

roscore


_2 терминал:_

catkin_make

source devel/setup.bash

rosrun dino_package dino_server


_3 терминал (топик):_

rostopic echo /dino_topic


_4 терминал (сервис):_

source devel/setup.bash

rosrun dino_package dino_client

# DinoGenerator
This is the first laboratory work.
---
5 вариант.

В задании не говорилось про создание клиента, но пока смотрела курс на stepik создала и решила с ним оставить. Без него все тоже работает.

ПОРЯДОК БЕЗ КЛИЕНТА: 

__1 терминал:__

roscore


__2 терминал:__

catkin_make

source devel/setup.bash

rosrun dino_package dino_server


__3 терминал (топик):__

rostopic echo /dino_topic


__4 терминал (сервис):__

source devel/setup.bash

rosservice call /dino_service "dino_begin: 'YOUR WORD '"



ПОРЯДОК С КЛИЕНТОМ: 

__1 терминал:__

roscore


__2 терминал:__

catkin_make

source devel/setup.bash

rosrun dino_package dino_server


__3 терминал (топик):__

rostopic echo /dino_topic


__4 терминал (сервис):__

source devel/setup.bash

rosrun dino_package dino_client

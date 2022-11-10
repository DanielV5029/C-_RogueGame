-Started by handling collisions between the player and the map by checking if players
next move is colliding with the array of the map with the case 'a'.
If so player is teleported back to its previous position.

-Pick-up an item was done by checking if players new position colliedes with the item on the map.
If so then teleport health out of map where the GUI is and add 1 to int health.
Same was done with armor item.

-Drop item was done by checking the players position and checking if the user clicked
on the button 'F'.
If F is clicked then drop item infront of the player by checking players x and y
co-ordinates. Then dropping the item +1 relative to players x position.

-Maintain multiple items was done by increasing the counter of health or armor when 2 of the same is
picked up.

-If the player presses number 1 or 2 on the keyboard,
then it checks whether the int health/armor is more than 0 and then allows
the player to drop the item.

-Drop multiple items is done by checking if player x+ is free, if yes then drop, if not then look players other positions for free space

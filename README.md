## Player:

- The player is represented by a shape which is defined in the config file.
- The player must spawn in the center of the screen at the beginning of the game, and after it dies (collides with an enemy).
- The player moves by a speed S read from the config file in these directions:
  - Up: W key, Left: A key, Down: S key, Right: D key.
- Note: Be careful to set the speed of the player appropriately.
  - If player is moving diagonally, it should not be traveling at speed S in both axes, but its total speed along the diagonal should be S.
  - You can accomplish this by normalizing the velocity then multiplying by S.
- The player is confined to move only within the bounds of the window.
- The player will shoot a bullet toward the mouse pointer when the left mouse button is clicked. The speed, size, and lifespan of the bullets are read from the config file.

## Enemy(s):

- Enemies will spawn in a random location on the screen every X frames, where X is defined in the configuration file.
- Enemies must not overlap the sides of the screen at the time of spawn.
- Enemy shapes have random number of vertices, between a given minimum and maximum number, which is specified in the config file.
- Enemy shape radius will be specified in the configuration file.
- Enemies will be given a random color upon spawning.
- Enemies will be given a random speed upon spawning, between a minimum and maximum value specified in the config file.
- When an enemy reaches the edge of the window, it should bounce off in the opposite direction at the same speed.
- When (large) enemies collide with a bullet or player, they are destroyed, and N small enemies spawn in its place, where N is the number of vertices of the original enemy. Each small enemy must have the same number of vertices and color of the original enemy. These small entities travel outward at angles at a fixed intervals equal to (360 / vertices). For example, if the original enemy had 6 sides, the 6 smaller enemies will travel outward in intervals of (360/6) = 60 degrees.
- Small enemies should be given a 'reasonable' speed.

# Configuration file

Window: WIDTH HEIGHT FRAME_LIMIT FULL_SCREEN
Player: SHAPE_RADIUS(int) COLLISION_RADIUS(int) SPEED(float) FILL_COLOR(int,int,int) OUTLINE_COLOR(int,int,int) OUTLINE_THICKNESS(int) SHAPE_VERTICES(int)
Enemy: SHAPE_RADIUS(int) COLLISION_RADIUS(int) SPEE_MIN/SPEED_MAX(float, float) OUTLINE_COLOR(int,int,int) OUTLINE_THICKNESS(int) VERTICES_MIN/VERTICES_MAX(int, int) LIFESPAN(int) SPAWN_INTERVAL(int)
Bullet: SHAPE_RADIUS(int) COLLISION_RADIUS(int) SPEED(float) FILL_COLOR(int,int,int) OUTLINE_COLOR(int,int,int) OUTLINE_THICKNESS(int) SHAPE_VERTICES(int) LIFESPAN (int)
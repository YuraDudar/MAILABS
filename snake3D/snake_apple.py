from ursina import *
from random import randrange


class Apple(Entity):
    def __init__(self, size_of_map, **kwargs):
        super().__init__(**kwargs)
        self.size_of_map = size_of_map
        self.new_position()

    def new_position(self):
        self.position = (randrange(self.size_of_map) + 0.5, randrange(self.size_of_map) + 0.5, -0.5)


class Snake:
    def __init__(self, size_of_map):
        self.MAP_SIZE = size_of_map
        self.snake_length = 1
        self.snake_head = [Vec3(randrange(size_of_map) + 0.5, randrange(size_of_map) + 0.5, -0.5)]
        self.snake_body = []
        self.create_segment(self.snake_head[0])
        self.directions = {'a': Vec3(-1, 0, 0), 'd': Vec3(1, 0, 0), 'w': Vec3(0, 1, 0), 's': Vec3(0, -1, 0)}
        self.direction = Vec3(0, 0, 0)
        self.permissions = {'a': 1, 'd': 1, 'w': 1, 's': 1}
        self.block_movement = {'a': 'd', 'd': 'a', 'w': 's', 's': 'w'}
        self.speed, self.score = 20, 0
        self.frame_counter = 0

    def add_segment(self):
        self.snake_length += 1
        self.score += 1
        self.create_segment(self.snake_head[0])

    def create_segment(self, position):
        entity = Entity(position=position)
        Entity(model='cube', texture='krasivo-8.jpg', position=position).add_script(
            SmoothFollow(speed=20, target=entity))
        self.snake_body.insert(0, entity)

    def run(self):
        self.frame_counter += 1
        if not(self.frame_counter % self.speed):
            self.snake_head.append(self.snake_head[-1] + self.direction)
            self.snake_head = self.snake_head[-self.snake_length:]
            for segment, segment_position in zip(self.snake_body, self.snake_head):
                segment.position = segment_position

    def control(self, key):
        for pressed_key in 'wasd':
            if pressed_key == key and self.permissions[pressed_key]:
                self.direction = self.directions[pressed_key]
                self.permissions = dict.fromkeys(self.permissions, 1)
                self.permissions[self.block_movement[pressed_key]] = 0
                break
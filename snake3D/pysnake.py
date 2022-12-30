from ursina import *
from snake_apple import *


class Game(Ursina):
    def __init__(self):
        super().__init__()
        window.fullscreen = True
        window.vsync = True
        self.size_of_map = 20
        camera.position = (self.size_of_map // 2, -21, -24)
        camera.rotation_x = -52
        self.start_new_game()

    def start_new_game(self):
        scene.clear()
        self.start_map(self.size_of_map)
        self.apple = Apple(self.size_of_map, model='sphere', rotation=(-90, 90, 0), texture='apple.jpg')
        self.snake = Snake(self.size_of_map)

    def start_map(self, size_of_map):
        Entity(model='quad', scale=size_of_map, position=(size_of_map // 2, size_of_map // 2, 0),
               color=color.white66, texture='white_cube', texture_scale=(20, 20))
        Entity(model='quad', scale=size_of_map, position=(size_of_map // 2, size_of_map // 2, 0),
               texture_scale=(20, 20), texture="трава_10.jpg")
        Entity(model='quad', scale=size_of_map * 3, position=(size_of_map // 2, size_of_map // 2, 1),
               color=color.white66, texture='closeupcloudysky.mp4')
        Entity(model=Grid(size_of_map, size_of_map), scale=size_of_map, position=(size_of_map // 2, size_of_map // 2, -0.01), color=color.black)

    def apple_eaten(self):
        if self.snake.snake_head[-1] == self.apple.position:
            self.snake.add_segment()
            self.apple.new_position()

    def game_over(self):
        lens_snake = self.snake.snake_head
        if 0 < lens_snake[-1][0] < self.size_of_map and 0 < lens_snake[-1][1] < self.size_of_map and len(lens_snake) == len(set(lens_snake)):
                return
        print_on_screen('GAME OVER', position=(-0.7, 0.1), scale=10, duration=1)
        self.snake.direction = Vec3(0, 0, 0)
        self.snake.permissions = dict.fromkeys(self.snake.permissions, 0)
        invoke(self.start_new_game, delay=1)

    def input(self, key, is_raw=False):
        super().input(key)
        self.snake.control(key)
        if key == '2':
            camera.rotation_x = 0
            camera.position = (self.size_of_map // 2, self.size_of_map // 2, -50)
        elif key == '3':
            camera.position = (self.size_of_map // 2, -21, -24)
            camera.rotation_x = -52

    def update(self):
        print_on_screen(f'Очки: {self.snake.score}', position=(-0.05, 0.45), scale=1, duration = 0.05)
        self.apple_eaten()
        self.game_over()
        self.snake.run()

if __name__ == '__main__':
    game = Game()
    update = game.update
    game.run()
import pygame
import random
import os

#màu sắc & thuộc tính
WHITE = (255,255,255)
BLACK = (0,0,0)
RED = (255,0,0)

FPS = 60
WIDTH = 500
HEIGHT = 600

running = True
auto_shoot = 0
score = 0
boss_key = True
light_bg = 0
bg_time_warning = False
bg_key =  False
start_key = True
# các hàm khởi tạo
pygame.init()
pygame.display.set_caption("sky war")
screen = pygame.display.set_mode((WIDTH,HEIGHT))
clock = pygame.time.Clock()
# tải hình ảnh lên
red_bg = pygame.image.load(os.path.join('image','bg3.png')).convert()
red_bg = pygame.transform.scale(red_bg,(500,600))
white_bg = pygame.image.load(os.path.join('image','background2.png')).convert()
white_bg = pygame.transform.scale(white_bg,(500,600))
background_img = pygame.image.load(os.path.join('image','bg1.jpg')).convert()
background_img = pygame.transform.scale(background_img,(500,600))

player_img = pygame.image.load(os.path.join('image','p0.png')).convert()
player_img =  pygame.transform.scale(player_img,(50,38))
player_img_sm =  pygame.transform.scale(player_img,(25,19))
player_img.set_colorkey(BLACK)
player_img_sm.set_colorkey(BLACK)

airplane_img = pygame.image.load(os.path.join('image','p3.png')).convert()
airplane_img.set_colorkey(BLACK)
airplane_img =  pygame.transform.scale(airplane_img,(50,38))


bullet_img = pygame.image.load(os.path.join('image','gair.png')).convert()
bullet_img =  pygame.transform.scale(bullet_img,(20,50))
bullet_img.set_colorkey(BLACK)

boss_img = pygame.image.load(os.path.join('image','boss.png')).convert()
boss_img =  pygame.transform.scale(boss_img,(200,195))
boss_img.set_colorkey(BLACK)

rocket_img = pygame.image.load(os.path.join('image','rocket.png')).convert()
rocket_img.set_colorkey(BLACK)
rocket_img =  pygame.transform.scale(rocket_img,(80,60))

warning_img = pygame.image.load(os.path.join('image','warning.png')).convert()
warning_img.set_colorkey(BLACK)
warning_img =  pygame.transform.scale(warning_img,(100,100))



# hình ảnh animation
item_imgs = {}
item_imgs['gun'] = pygame.image.load(os.path.join('image','gun.png')).convert()
item_imgs['gun'] =  pygame.transform.scale(item_imgs['gun'],(10,20))
item_imgs['lives'] = pygame.image.load(os.path.join('image','lives.png')).convert()
item_imgs['lives'] =  pygame.transform.scale(item_imgs['lives'],(25,22))
item_imgs['lives'].set_colorkey(BLACK)

gun_air_img = pygame.image.load(os.path.join('image','bullet.png')).convert()
gun_air_img =  pygame.transform.scale(gun_air_img ,(6,20))
gun_air_img.set_colorkey(BLACK)

anim_imgs = {}
anim_imgs['kill'] = []
anim_imgs['nuc'] = []
anim_imgs['collide'] = []
anim_imgs['fire'] = []
for i in range(9):
    if i < 3:
        anim_imgs['fire'].append(pygame.image.load(os.path.join('image',f'fire{i}.png')).convert())
        anim_imgs['fire'][i].set_colorkey(BLACK)
    anim_imgs['kill'].append(pygame.image.load(os.path.join('image',f'player_expl{i}.png')).convert())
    anim_imgs['kill'][i].set_colorkey(BLACK)
    anim_imgs['nuc'].append(pygame.image.load(os.path.join('image',f'e{i}.png')).convert())
    anim_imgs['nuc'][i].set_colorkey(BLACK)


# tải âm thanh lên
shoot3_sound = pygame.mixer.Sound(os.path.join('sound','pow1.wav'))
shoot_sound = pygame.mixer.Sound(os.path.join('sound','shoot.wav'))

### HÀM
def bosshp_draw(surf,x,y,hp):
    if hp < 0:
        hp = 0
    hp = (hp /300) *100
    hp_surf = pygame.Rect(x,y,hp,5)
    hp_surf_border = pygame.Rect(x,y,100,5)
    pygame.draw.rect(surf,RED,hp_surf)
    pygame.draw.rect(surf,WHITE,hp_surf_border,1)
def text_draw(surf,text,size,x,y,color):
    font_type = pygame.font.match_font('arial',True)
    font = pygame.font.Font(font_type,size)
    text_surf = font.render(text,True,color)
    text_rect = text_surf.get_rect()
    text_rect.x = x
    text_rect.y = y
    surf.blit(text_surf,text_rect)
def lives_draw(surf,lives,img):
    for i in range(lives):
        live_rect = img.get_rect()
        live_rect.x = 350 + (i*30)
        live_rect.y = 10
        surf.blit(img,live_rect)
def start():
    screen.blit(white_bg,(0,0))
    text_draw(screen,'sky war',65,150,50,BLACK)
    text_draw(screen,'> START <',30,190,HEIGHT/2,RED)
    pygame.display.update()
    start_key = True
    while start_key:
        clock.tick(FPS)
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
            elif event.type == pygame.KEYUP:
                start_key = False
def warning_boss(light_bg):
    if 0<light_bg<=15 :
        screen.blit(background_img,(0,0))
        screen.blit(warning_img,(200,250))
    if 15<light_bg<=25:
        screen.blit(white_bg,(0,0))
        screen.blit(warning_img,(200,250))
    if 25 < light_bg <=30:
        screen.blit(red_bg,(0,0))
        screen.blit(warning_img,(200,250))
        


    
### CLASS
class Player(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = player_img
        self.rect = self.image.get_rect()
        self.rect.centerx = WIDTH / 2
        self.rect.bottom = HEIGHT - 10
        self.speedx = 8
        self.speedy = 8
        self.lives = 5
        self.gun = 1
        self.bullet = bullet_img
        self.check_time = 0
        self.key = True
    def update(self):
        now_time = pygame.time.get_ticks()
        if self.rect.y <  HEIGHT/2 and self.key:
            self.check_time = pygame.time.get_ticks()
            self.key = False
        if now_time - self.check_time > 600:
            self.rect.bottom = HEIGHT - 10
            self.key = True
        key_pressed = pygame.key.get_pressed()
        if key_pressed[pygame.K_a]:
            self.rect.x -= self.speedx
        if key_pressed[pygame.K_d]:
            self.rect.x += self.speedx
        if self.rect.bottom > HEIGHT:
            self.rect.bottom = HEIGHT
        if self.rect.left < 0:
            self.rect.left = 0
        if self.rect.right > WIDTH:
            self.rect.right = WIDTH
        
    def shoot(self):
        if self.gun == 1:
            bullet = Bullet(self.rect.centerx,self.rect.top,-20,self.bullet)
            all_sprites.add(bullet)
            player_bullets.add(bullet)
            boss.add(bullet)
            shoot_sound.play()
        elif self.gun ==2:
            bullet1 = Bullet(self.rect.right,self.rect.centery,-20,self.bullet)
            bullet2 = Bullet(self.rect.left,self.rect.centery,-20,self.bullet)
            all_sprites.add(bullet1)
            player_bullets.add(bullet1)
            all_sprites.add(bullet2)
            player_bullets.add(bullet2)
            boss.add(bullet1)
            boss.add(bullet2)
            shoot3_sound.play()
        else:
            bullet1 = Bullet(self.rect.right,self.rect.centery,-20,self.bullet)
            bullet2 = Bullet(self.rect.left,self.rect.centery,-20,self.bullet)
            bullet = Bullet(self.rect.centerx,self.rect.top,-20,self.bullet)
            all_sprites.add(bullet)
            player_bullets.add(bullet)
            all_sprites.add(bullet1)
            player_bullets.add(bullet1)
            all_sprites.add(bullet2)
            player_bullets.add(bullet2)
            boss.add(bullet)
            boss.add(bullet1)
            boss.add(bullet2)
            shoot3_sound.play()
class Enemy(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = airplane_img
        self.rect = self.image.get_rect()
        self.rect.x = random.randrange(1,449)
        self.rect.y = -40
        self.speedy = 2
        self.speedx = 2
        self.airplane_score = 100
        self.time_ago = pygame.time.get_ticks()
        self.frame_rate = random.randrange(2000,5000)
        self.bullet = gun_air_img
        self.line_up = -70
        self.line_down = 0
        self.bullet_speed = random.randrange(1,8)
    def update(self):
        self.air_shoot()
        if self.rect.top < self.line_up:
            self.speedy = -self.speedy
        if self.rect.bottom > self.line_down:
            self.speedy = -self.speedy
            self.line_down += 50
            self.line_up += 30
        if self.rect.left <= 0 or self.rect.right >= WIDTH:
            self.speedx = -self.speedx
        self.rect.x += self.speedx
        self.rect.y += self.speedy
        if self.rect.top > HEIGHT:
            self.rect.x = random.randrange(1,449)
            self.rect.y = random.randrange(-80,-50)
            self.speedy = random.randrange(1,2)
            self.speedx = random.randrange(-2,2)
    def air_shoot(self):
        now_time = pygame.time.get_ticks()
        if now_time - self.time_ago > self.frame_rate:
            bullet = Bullet(self.rect.centerx,self.rect.bottom,self.bullet_speed,self.bullet)
            all_sprites.add(bullet)
            enemy_bullets.add(bullet)
            self.time_ago = now_time       
class Bullet(pygame.sprite.Sprite):
    def __init__(self,x,y,speedy,img):
        pygame.sprite.Sprite.__init__(self)
        self.image = img
        self.rect = self.image.get_rect()
        self.rect.centerx = x
        self.rect.bottom = y
        self.speedy = speedy
    def update(self):
        self.rect.y += self.speedy
        if self.rect.bottom < 0 or self.rect.top > HEIGHT:
            self.kill()
class Item(pygame.sprite.Sprite):
    def __init__(self,center):
        pygame.sprite.Sprite.__init__(self)
        self.type = random.choice(['gun','lives'])
        self.image = item_imgs[self.type]
        self.image.set_colorkey(BLACK)
        self.rect = self.image.get_rect()
        self.rect.center = center
        self.speedy = 3
    def update(self):
        self.rect.y += self.speedy
        if self.rect.top > HEIGHT:
            self.kill()
class Expl_anim(pygame.sprite.Sprite):
    def __init__(self,center,anim_img):
        pygame.sprite.Sprite.__init__(self)
        self.anim_type = anim_img
        self.image = anim_imgs[self.anim_type][0]
        self.rect = self.image.get_rect()
        self.rect.center = center
        self.time_ago = pygame.time.get_ticks()
        self.time_rate = 50
        self.count = 0
    def update(self):
        now_time = pygame.time.get_ticks()
        if now_time - self.time_ago > self.time_rate:
            center = self.rect.center
            self.image = anim_imgs[self.anim_type][self.count]
            self.count += 1
            self.rect = self.image.get_rect()
            self.rect.center = center
            self.time_ago = now_time
            if self.count == len(anim_imgs[self.anim_type]):
                self.count = 1
                self.kill()
class Boss(pygame.sprite.Sprite):
    def __init__(self):
        pygame.sprite.Sprite.__init__(self)
        self.image = boss_img
        self.rect = self.image.get_rect()
        self.rect.center = (250,-150)
        self.speedy = 1
        self.time_call_funt = pygame.time.get_ticks()
        self.time_rate = 80
        self.hp = 300
        self.check = False
        self.boss_turn = pygame.transform.rotate(self.image,180)
        self.time_call_funt2 = pygame.time.get_ticks()
        self.time_shoot = 0
        self.check2 = True
        self.rocket_timedown = 0
        self.check3 = False
    def update(self):
        now_time = pygame.time.get_ticks()
        if now_time - self.rocket_timedown > 1200 and self.check3:
            a1 = random.randrange(1,430)
            a2 = random.randrange(1,430)
            b1 = Boss_skill(a1,0,16)
            b2 = Boss_skill(a2,0,16)
            boss_skill.add(b1)
            boss.add(b1)
            boss_skill.add(b2)
            boss.add(b2)
            self.rocket_timedown = now_time
        now_time = pygame.time.get_ticks()
        if now_time - self.time_call_funt2 > self.time_rate and self.check:
            self.check2 = False
            r = Boss_skill(self.rect.right-70,self.rect.centery,-30)
            l = Boss_skill(self.rect.left+10,self.rect.centery,-30)
            boss.add(r)
            boss.add(l)
            self.time_call_funt2 = now_time
            if now_time -  self.time_shoot > 1500:
                self.check2 = True
                self.check = False
                self.check3 = True
                self.image = boss_img
                self.rocket_timedown = pygame.time.get_ticks()
        now_time = pygame.time.get_ticks()
        if now_time - self.time_call_funt > self.time_rate:
            self.boss_anim()
            self.time_call_funt = now_time
        self.rect.y += self.speedy
        if self.rect.y == 100:
            self.speedy = 0
            self.image = self.boss_turn
            self.check = True
            self.set_time = 0
            self.time_shoot = pygame.time.get_ticks()
            self.rect.y -= 1

    def boss_anim(self):
        if self.check2:
            self.time_call_funt = pygame.time.get_ticks()
            f = Expl_anim((self.rect.centerx-2,self.rect.top-50),'fire')
            all_sprites.add(f)
            boss.add(f)
class Boss_skill(pygame.sprite.Sprite):
    def __init__(self,x,y,spy):
        pygame.sprite.Sprite.__init__(self)
        self.image = rocket_img
        self.rect = self.image.get_rect()
        self.rect.bottom = y
        self.rect.x = x
        self.speedy = spy
        self.expl_line = HEIGHT - 10
        self.turn_up_img = pygame.transform.rotate(self.image,180)
        
    def update(self):
        if self.speedy > 0 :
            self.image = self.turn_up_img
        self.rect.y += self.speedy
        if self.rect.bottom < 0:
            self.kill()
        if self.rect.bottom > 580:
            k = Expl_anim((self.rect.centerx,self.rect.centery-30),'nuc')
            boss.add(k)
            self.kill()

### GROUP
player = Player()
enemy = Enemy()
all_sprites = pygame.sprite.Group()
boss = pygame.sprite.Group()
all_enemy = pygame.sprite.Group()
player_bullets = pygame.sprite.Group()
all_sprites.add(player)
items = pygame.sprite.Group()
enemy_bullets = pygame.sprite.Group()
boss_skill = pygame.sprite.Group()
b = Boss()

for i in range(12):
    a = Enemy()
    all_sprites.add(a)
    all_enemy.add(a)


#main loop
while running:
    clock.tick(FPS)
    if start_key:
        start()
        start_key = False
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.K_q:
            FPS = 0
        if event.type == pygame.K_e:
            FPS = 0
        elif event.type == pygame.KEYDOWN:
            if event.key == pygame.K_q:
                FPS = 1
            if event.key == pygame.K_e:
                FPS = 60
                    




#xử lý va chạm
    if score >= 5000 and boss_key:
        pl_gun = player.gun
        pl_lives = player.lives
        pygame.sprite.Group.empty(all_sprites)
        if not pygame.sprite.Sprite.alive(player):
            player = Player()
            boss.add(player)
            player.gun = pl_gun
            player.lives = pl_lives
            boss.add(b)
            bg_key = True
        screen.blit(white_bg,(0,0))
        hits = pygame.sprite.spritecollide(player,boss_skill,True)
        for i in hits:
            player.gun = 1
            player.lives -= 1
            player.rect.y = -200
            if player.lives == 0:
                running = False
        hits = pygame.sprite.spritecollide(b,player_bullets,True)
        for i in hits:
            b.hp -= 2
            if b.hp < 0:
                score += 3000
                boss_key = False
                b.kill()
    else:
        hits = pygame.sprite.groupcollide(all_enemy,player_bullets,True,True)
        for i in hits:
            k = Expl_anim(i.rect.center,'kill')
            all_sprites.add(k)
            if random.random() > 0.8:
                item = Item(i.rect.center)
                all_sprites.add(item)
                items.add(item)
            score += i.airplane_score
            a = Enemy()
            all_sprites.add(a)
            all_enemy.add(a)
        hits = pygame.sprite.spritecollide(player,items,True)
        for i in hits:
            if i.type == 'gun':
                player.gun +=1
            if i.type == 'lives':
                player.lives += 1
                if player.lives > 5:
                    player.lives = 5
        hits = pygame.sprite.spritecollide(player,all_enemy,True)
        for i in hits:
            k = Expl_anim(i.rect.center,'collide')
            all_sprites.add(k)
            player.lives -= 1
            if player.gun >=2:
                player.gun = 1
            if player.lives <= 0:
                running = False
        hits = pygame.sprite.spritecollide(player,enemy_bullets,True)
        for i in hits:
            if player.gun >=2:
                player.gun = 1
            player.lives -= 1
            if player.lives <= 0:
                running = False
            k = Expl_anim(i.rect.center,'kill')
            all_sprites.add(k)
        all_sprites.update()

    
    # cập nhật
    boss.update()
    auto_shoot +=1
    if auto_shoot == 30:
        player.shoot()
        auto_shoot = 0
    if score >= 5000 and bg_key:
        light_bg += 1
        warning_boss(light_bg)
        if light_bg == 30:
            light_bg = 0
        bg_time_warning += 1
        if bg_time_warning == 180:
            bg_key = False
    else:
        screen.blit(background_img,(0,0))

    # hiển thị
    text_draw(screen,str(int(score)),18,245,10,WHITE)
    lives_draw(screen,player.lives,player_img_sm)
    all_sprites.draw(screen)
    boss.draw(screen)
    if pygame.sprite.Sprite.alive(b):
        bosshp_draw(screen,b.rect.centerx-50,b.rect.bottom,b.hp)
    pygame.display.update()
pygame.quit()
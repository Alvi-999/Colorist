#include "raylib.h"
#include "player.h"


// // --------------Animation------------------------------
// Texture2D IdleRightAnimation(Player *player)
// {
//     if(player->framecount>=0 && player->framecount<5)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-1.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=5 && player.framecount<10)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-2.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=10 && player.framecount<15)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-3.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=15 && player.framecount<20)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-4.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=20 && player.framecount<25)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-5.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=25 && player.framecount<30)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-6.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=30 && player.framecount<35)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-7.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=35 && player.framecount<40)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-8.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=40 && player.framecount<45)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-9.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=45 && player.framecount<50)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-10.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=50 && player.framecount<55)
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-11.png");
//         return SpriteImage;
//     }
//     else
//     {
//         Texture2D SpriteImage = LoadTexture("idler/idler-12.png");
//         return SpriteImage;
//     }
// }

// Texture2D IdleLeftAnimation(Player &player)
// {
//     if(player.framecount>=0 && player.framecount<5)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-1.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=5 && player.framecount<10)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-2.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=10 && player.framecount<15)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-3.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=15 && player.framecount<20)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-4.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=20 && player.framecount<25)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-5.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=25 && player.framecount<30)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-6.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=30 && player.framecount<35)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-7.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=35 && player.framecount<40)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-8.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=40 && player.framecount<45)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-9.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=45 && player.framecount<50)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-10.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=50 && player.framecount<55)
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-11.png");
//         return SpriteImage;
//     }
//     else
//     {
//         Texture2D SpriteImage = LoadTexture("idlel/idlel-12.png");
//         return SpriteImage;
//     }
// }

// Texture2D RunRightAnimation(Player &player)
// {
//     if(player.framecount>=0 && player.framecount<5)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-1.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=5 && player.framecount<10)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-2.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=10 && player.framecount<15)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-3.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=15 && player.framecount<20)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-4.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=20 && player.framecount<25)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-5.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=25 && player.framecount<30)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-6.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=30 && player.framecount<35)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-7.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=35 && player.framecount<40)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-8.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=40 && player.framecount<45)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-9.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=45 && player.framecount<50)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-10.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=50 && player.framecount<55)
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-11.png");
//         return SpriteImage;
//     }
//     else
//     {
//         Texture2D SpriteImage = LoadTexture("runr/runr-12.png");
//         return SpriteImage;
//     }
// }

// Texture2D RunLeftAnimation(Player &player)
// {
//     if(player.framecount>=0 && player.framecount<5)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-1.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=5 && player.framecount<10)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-2.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=10 && player.framecount<15)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-3.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=15 && player.framecount<20)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-4.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=20 && player.framecount<25)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-5.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=25 && player.framecount<30)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-6.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=30 && player.framecount<35)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-7.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=35 && player.framecount<40)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-8.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=40 && player.framecount<45)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-9.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=45 && player.framecount<50)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-10.png");
//         return SpriteImage;
//     }
//     else if(player.framecount>=50 && player.framecount<55)
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-11.png");
//         return SpriteImage;
//     }
//     else
//     {
//         Texture2D SpriteImage = LoadTexture("runl/runl-12.png");
//         return SpriteImage;
//     }
// }
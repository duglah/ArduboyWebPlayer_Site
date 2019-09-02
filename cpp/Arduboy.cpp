#include "Arduboy.h"

Arduboy::Arduboy() {

}

void Arduboy::begin()
{
//   boot(); // required
//   bootUtils();

//   bootLogo();

//   // Audio
//   tunes.initChannel(PIN_SPEAKER_1);
//   tunes.initChannel(PIN_SPEAKER_2);
//   audio.begin();
    jsBegin();
}

void Arduboy::setFrameRate(uint8_t rate)
{
// frameRate = rate;
// eachFrameMillis = 1000/rate;
    jsSetFrameRate(rate);
}

bool Arduboy::nextFrame()
{
//   long now = millis();
//   uint8_t remaining;

//   // post render
//   if (post_render) {
//     lastFrameDurationMs = now - lastFrameStart;
//     frameCount++;
//     post_render = false;
//   }

//   // if it's not time for the next frame yet
//   if (now < nextFrameStart) {
//     remaining = nextFrameStart - now;
//     // if we have more than 1ms to spare, lets sleep
//     // we should be woken up by timer0 every 1ms, so this should be ok
//     if (remaining > 1)
//       idle();
//     return false;
//   }

//   // pre-render

//   // technically next frame should be last frame + each frame but if we're
//   // running a slow render we would constnatly be behind the clock
//   // keep an eye on this and see how it works.  If it works well the
//   // lastFrameStart variable could be eliminated completely
//   nextFrameStart = now + eachFrameMillis;
//   lastFrameStart = now;
//   post_render = true;
//   return post_render;
return jsNextFrame();
}

void Arduboy::setCursor(int16_t x, int16_t y)
{
//   cursor_x = x;
//   cursor_y = y;
    jsSetCursor(x, y);
}

void Arduboy::clear()
{
  fillScreen(BLACK);
  jsClear();
}

void Arduboy::display()
{
  //this->paintScreen(sBuffer);
    jsDisplay(&sBuffer[0]);
}

void Arduboy::print(const char* text) {
    jsPrint(text);
}

void Arduboy::drawBitmap
(int16_t x, int16_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, 
 uint8_t color)
{
  // no need to dar at all of we're offscreen
  if (x+w < 0 || x > WIDTH-1 || y+h < 0 || y > HEIGHT-1)
      return;

  int yOffset = abs(y) % 8;
  int sRow = y / 8;
  if (y < 0) {
    sRow--;
    yOffset = 8 - yOffset;
  }
  int rows = h/8;
  if (h%8!=0) rows++;
  for (int a = 0; a < rows; a++) {
    int bRow = sRow + a;
    if (bRow > (HEIGHT/8)-1) break;
    if (bRow > -2) {
      for (int iCol = 0; iCol<w; iCol++) {
        if (iCol + x > (WIDTH-1)) break;
        if (iCol + x >= 0) {
          if (bRow >= 0) {
            if      (color == WHITE) this->sBuffer[ (bRow*WIDTH) + x + iCol ] |= pgm_read_byte(bitmap+(a*w)+iCol) << yOffset;
            else if (color == BLACK) this->sBuffer[ (bRow*WIDTH) + x + iCol ] &= ~(pgm_read_byte(bitmap+(a*w)+iCol) << yOffset);
            else                     this->sBuffer[ (bRow*WIDTH) + x + iCol ] ^= pgm_read_byte(bitmap+(a*w)+iCol) << yOffset;
          }
          if (yOffset && bRow<(HEIGHT/8)-1 && bRow > -2) {
            if      (color == WHITE) this->sBuffer[ ((bRow+1)*WIDTH) + x + iCol ] |= pgm_read_byte(bitmap+(a*w)+iCol) >> (8-yOffset);
            else if (color == BLACK) this->sBuffer[ ((bRow+1)*WIDTH) + x + iCol ] &= ~(pgm_read_byte(bitmap+(a*w)+iCol) >> (8-yOffset));
            else                     this->sBuffer[ ((bRow+1)*WIDTH) + x + iCol ] ^= pgm_read_byte(bitmap+(a*w)+iCol) >> (8-yOffset);
          }
        }
      }
    }
  }
}

void Arduboy::fillScreen(uint8_t color)
{
    if (color) color = 0xFF;  //change any nonzero argument to b11111111 and insert into screen array.
    for(int16_t i=0; i<1024; i++)  { sBuffer[i] = color; }  //sBuffer = (128*64) = 8192/8 = 1024 bytes. 
}

void Arduboy::drawPixel(int x, int y, uint8_t color)
{
  #ifdef PIXEL_SAFE_MODE
  if (x < 0 || x > (WIDTH-1) || y < 0 || y > (HEIGHT-1))
  {
    return;
  }
  #endif

  uint8_t row = (uint8_t)y / 8;
  if (color)
  {
    sBuffer[(row*WIDTH) + (uint8_t)x] |=   _BV((uint8_t)y % 8);
  }
  else
  {
    sBuffer[(row*WIDTH) + (uint8_t)x] &= ~ _BV((uint8_t)y % 8);
  }
}
#include <transformer.hh>

allrgb::Transformer::Transformer(cv::Mat& input)
  : img_(input)
  , colors_(9)
{}

cv::Mat&
allrgb::Transformer::img_get() const
{
  return img_;
}

void
allrgb::Transformer::operator()()
{
  for (auto it = img_.begin<cv::Vec3b>(); it != img_.end<cv::Vec3b>(); ++it)
    replace_color(*it);
}

void
allrgb::Transformer::replace_color(cv::Vec3b& color)
{
  color = color;
}

// bit_index = 0 is the LSB
uchar
allrgb::Transformer::bdigit(uchar value, size_t bit_index)
{
  unsigned mask = 0b00000001 << bit_index;
  return (value & mask) >> bit_index;
}


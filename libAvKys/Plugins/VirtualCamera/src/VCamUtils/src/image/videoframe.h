/* Webcamoid, webcam capture application.
 * Copyright (C) 2017  Gonzalo Exequiel Pedone
 *
 * Webcamoid is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamoid is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamoid. If not, see <http://www.gnu.org/licenses/>.
 *
 * Web-Site: http://webcamoid.github.io/
 */

#ifndef VIDEOFRAME_H
#define VIDEOFRAME_H

#include <string>
#include <memory>

#include "videoformattypes.h"
#include "videoframetypes.h"

namespace AkVCam
{
    class VideoFramePrivate;
    class VideoFormat;

    class VideoFrame
    {
        public:
            VideoFrame();
            VideoFrame(const std::string &fileName);
            VideoFrame(std::streambuf *stream);
            VideoFrame(std::istream *stream);
            VideoFrame(const VideoFormat &format,
                       const std::shared_ptr<uint8_t> &data,
                       size_t dataSize);
            VideoFrame(const VideoFormat &format,
                       const uint8_t *data,
                       size_t dataSize);
            VideoFrame(const VideoFrame &other);
            VideoFrame &operator =(const VideoFrame &other);
            ~VideoFrame();

            bool load(const std::string &fileName);
            bool load(std::streambuf *stream);
            bool load(std::istream *stream);
            VideoFormat format() const;
            VideoFormat &format();
            std::shared_ptr<uint8_t> data() const;
            std::shared_ptr<uint8_t> &data();
            size_t dataSize() const;
            size_t &dataSize();
            void clear();

            VideoFrame mirror(bool horizontalMirror, bool verticalMirror) const;
            VideoFrame scaled(int width,
                              int height,
                              Scaling mode=ScalingFast,
                              AspectRatio aspectRatio=AspectRatioIgnore) const;
            VideoFrame scaled(size_t maxArea,
                              Scaling mode=ScalingFast,
                              int align=32) const;
            VideoFrame swapRgb(bool swap) const;
            VideoFrame swapRgb() const;
            bool canConvert(FourCC input, FourCC output) const;
            VideoFrame convert(FourCC fourcc) const;
            VideoFrame adjustHsl(int hue, int saturation, int luminance);
            VideoFrame adjustGamma(int gamma);
            VideoFrame adjustContrast(int contrast);
            VideoFrame toGrayScale();
            VideoFrame adjust(int hue,
                              int saturation,
                              int luminance,
                              int gamma,
                              int contrast,
                              bool gray);

        private:
            VideoFramePrivate *d;
    };
}

#endif // VIDEOFRAME_H
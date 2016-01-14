/*
 * Copyright (c) 2015 Kevin Wheatley <kevin.j.wheatley@gmail.com>
 *
 * This file is part of FFmpeg.
 *
 * FFmpeg is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * FFmpeg is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with FFmpeg; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "libavutil/color_utils.h"
#include "libavutil/pixfmt.h"

double avpriv_get_gamma_from_trc(enum AVColorTransferCharacteristic trc)
{
    double gamma;
    switch (trc) {
        case AVCOL_TRC_BT709:
        case AVCOL_TRC_SMPTE170M:
        case AVCOL_TRC_SMPTE240M:
        case AVCOL_TRC_BT1361_ECG:
        case AVCOL_TRC_BT2020_10:
        case AVCOL_TRC_BT2020_12:
            /* these share a segmented TRC, but gamma 1.961 is a close
              approximation, and also more correct for decoding content */
            gamma = 1.961;
            break;
        case AVCOL_TRC_GAMMA22:
        case AVCOL_TRC_IEC61966_2_1:
            gamma = 2.2;
            break;
        case AVCOL_TRC_GAMMA28:
            gamma = 2.8;
            break;
        case AVCOL_TRC_LINEAR:
            gamma = 1.0;
            break;
        default:
            gamma = 0.0; // Unknown value representation
    }
    return gamma;
}

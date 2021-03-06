/*!
 * \file glyph_render_data.cpp
 * \brief file glyph_render_data.cpp
 *
 * Copyright 2016 by Intel.
 *
 * Contact: kevin.rogovin@intel.com
 *
 * This Source Code Form is subject to the
 * terms of the Mozilla Public License, v. 2.0.
 * If a copy of the MPL was not distributed with
 * this file, You can obtain one at
 * http://mozilla.org/MPL/2.0/.
 *
 * \author Kevin Rogovin <kevin.rogovin@intel.com>
 *
 */


#include <fastuidraw/text/glyph_render_data.hpp>

//////////////////////////////////////
// GlyphRender methods
fastuidraw::GlyphRender::
GlyphRender(int pixel_size):
  m_type(coverage_glyph),
  m_pixel_size(pixel_size)
{}

fastuidraw::GlyphRender::
GlyphRender(enum glyph_type t):
  m_type(t),
  m_pixel_size(0)
{
  FASTUIDRAWassert(scalable(t) && t != invalid_glyph);
}

fastuidraw::GlyphRender::
GlyphRender(void):
  m_type(invalid_glyph),
  m_pixel_size(0)
{}

bool
fastuidraw::GlyphRender::
operator<(const GlyphRender &rhs) const
{
  if(m_type != rhs.m_type)
    {
      return m_type < rhs.m_type;
    }

  if(!scalable(m_type))
    {
      return m_pixel_size < rhs.m_pixel_size;
    }

  return false;
}

bool
fastuidraw::GlyphRender::
operator==(const GlyphRender &rhs) const
{
  return m_type == rhs.m_type
    && (scalable(m_type) || m_pixel_size == rhs.m_pixel_size);
}

bool
fastuidraw::GlyphRender::
valid(void) const
{
  return (m_type != invalid_glyph) &&
    (scalable(m_type) || m_pixel_size > 0);
}

bool
fastuidraw::GlyphRender::
scalable(enum glyph_type tp)
{
  return tp != coverage_glyph;
}

////////////////////////////////////
// fastuidraw::GlyphRenderData methods
fastuidraw::GlyphRenderData::
~GlyphRenderData()
{
}

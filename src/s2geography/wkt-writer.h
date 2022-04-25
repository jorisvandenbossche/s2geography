
#pragma once

#include <memory>
#include <sstream>

#include "s2geography/geoarrow-imports.h"
#include "s2geography/geography.h"

namespace s2geography {

class WKTWriter {
 public:
  WKTWriter();
  std::string write_feature(const S2Geography& geog);

 private:
  std::unique_ptr<Handler> exporter_;
  util::GeometryType geometry_type_;
  std::stringstream stream_;

  Handler::Result handle_points(const PointGeography& geog, Handler* handler);
  Handler::Result handle_polylines(const PolylineGeography& geog,
                                   Handler* handler);
  Handler::Result handle_polygon(const PolygonGeography& geog,
                                 Handler* handler);
  Handler::Result handle_collection(const S2GeographyCollection& geog,
                                    Handler* handler);
  Handler::Result handle_feature(const S2Geography& geog, Handler* handler);
};

}  // namespace s2geography

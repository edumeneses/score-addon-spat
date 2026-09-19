#pragma once

#include <Gris/Algo/SpeakerSetup.hpp>

#include <ossia/network/value/value.hpp>

#include <optional>

namespace Gris
{
[[nodiscard]] std::optional<SpeakerSetup> speakerSetupFromValue(ossia::value const& v);
} // namespace Gris

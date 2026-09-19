#pragma once

#include <Gris/Algo/SpeakerSetup.hpp>

#include <QString>

#include <optional>

namespace Gris
{
enum class SpeakerSetupFormat
{
  unknown,
  legacy,       //! <SPEAKER_SETUP VERSION="3.x">, flat SPEAKER_n list
  intermediate,
  valueTree
};

struct SpeakerSetupReadResult
{
  std::optional<SpeakerSetup> setup{};
  SpeakerSetupFormat format{SpeakerSetupFormat::unknown};
  QString error{};

  [[nodiscard]] explicit operator bool() const noexcept { return setup.has_value(); }
};

[[nodiscard]] SpeakerSetupReadResult readSpeakerSetup(QByteArray const& xml);

[[nodiscard]] SpeakerSetupReadResult readSpeakerSetupFile(QString const& path);

[[nodiscard]] QByteArray writeSpeakerSetup(SpeakerSetup const& setup);

[[nodiscard]] QString writeSpeakerSetupFile(SpeakerSetup const& setup, QString const& path);

}

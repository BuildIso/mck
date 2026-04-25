; ------------------------------------------------------------
; mck Installer (Inno Setup Script)
; ------------------------------------------------------------

[Setup]
AppName=mck
AppVersion=2026.2
AppPublisher=BuildIso
DefaultDirName={commonpf}\mck
DefaultGroupName=mck
OutputDir=.
OutputBaseFilename=mck-installer
Compression=lzma
SolidCompression=yes
ArchitecturesInstallIn64BitMode=x64compatible

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Files]
Source: "..\include\*"; DestDir: "{app}\include"; Flags: recursesubdirs createallsubdirs
Source: "..\src\*";     DestDir: "{app}\src";     Flags: recursesubdirs createallsubdirs
Source: "..\asm\*";     DestDir: "{app}\asm";     Flags: recursesubdirs createallsubdirs
Source: "..\cpp\*";     DestDir: "{app}\cpp";     Flags: recursesubdirs createallsubdirs
Source: "..\kernel\*";  DestDir: "{app}\kernel";  Flags: recursesubdirs createallsubdirs
Source: "..\ld\*";      DestDir: "{app}\ld";      Flags: recursesubdirs createallsubdirs
Source: "..\tools\*";   DestDir: "{app}\tools";   Flags: recursesubdirs createallsubdirs
Source: "..\docs\*";    DestDir: "{app}\docs";    Flags: recursesubdirs createallsubdirs
Source: "..\rust\*";    DestDir: "{app}\rust";    Flags: recursesubdirs createallsubdirs
Source: "..\build\*";    DestDir: "{app}\build";    Flags: recursesubdirs createallsubdirs
Source: "..\*"; DestDir: "{app}"; Flags: ignoreversion

[Icons]
Name: "{group}\mck (Project Folder)"; Filename: "{app}"
Name: "{group}\Uninstall mck";        Filename: "{uninstallexe}"

[Run]

[UninstallDelete]
Type: filesandordirs; Name: "{app}"
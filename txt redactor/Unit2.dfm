object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 202
  ClientWidth = 447
  Color = clHighlight
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  WindowMenu = open1
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 240
    Top = 32
    Width = 31
    Height = 13
    Caption = 'Label1'
  end
  object Memo1: TMemo
    Left = 0
    Top = 0
    Width = 447
    Height = 202
    Align = alClient
    Lines.Strings = (
      '')
    TabOrder = 0
  end
  object MainMenu1: TMainMenu
    Left = 96
    Top = 40
    object file1: TMenuItem
      Caption = 'file'
      object New1: TMenuItem
        Caption = 'New'
        OnClick = New1Click
      end
      object open1: TMenuItem
        Caption = 'open'
        OnClick = open1Click
      end
      object save1: TMenuItem
        Caption = 'save'
        OnClick = save1Click
      end
      object saveas1: TMenuItem
        Caption = 'save as'
        OnClick = saveas1Click
      end
      object exit1: TMenuItem
        Caption = 'exit'
        OnClick = exit1Click
      end
    end
  end
  object OpenDialog1: TOpenDialog
    Left = 328
    Top = 56
  end
  object SaveDialog1: TSaveDialog
    DefaultExt = '*.txt'
    Filter = 'notepad|*.txt|word|*.doc'
    Left = 232
    Top = 80
  end
end

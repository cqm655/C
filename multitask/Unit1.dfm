object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 260
  ClientWidth = 447
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Button1: TButton
    Left = 56
    Top = 24
    Width = 121
    Height = 49
    Caption = 'Start'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 33
    Top = 107
    Width = 97
    Height = 145
    TabOrder = 1
  end
  object Button2: TButton
    Left = 304
    Top = 24
    Width = 105
    Height = 49
    Caption = 'STOP'
    TabOrder = 2
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 183
    Top = 24
    Width = 115
    Height = 49
    Caption = 'PAUSE'
    TabOrder = 3
    OnClick = Button3Click
  end
  object Memo2: TMemo
    Left = 136
    Top = 107
    Width = 97
    Height = 145
    TabOrder = 4
  end
  object Memo3: TMemo
    Left = 239
    Top = 107
    Width = 97
    Height = 145
    TabOrder = 5
  end
  object Memo4: TMemo
    Left = 342
    Top = 107
    Width = 97
    Height = 145
    TabOrder = 6
  end
end

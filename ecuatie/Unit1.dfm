object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 202
  ClientWidth = 753
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object egal: TButton
    Left = 64
    Top = 96
    Width = 75
    Height = 25
    Caption = 'egal'
    TabOrder = 0
    OnClick = egalClick
  end
  object clear: TButton
    Left = 480
    Top = 96
    Width = 75
    Height = 25
    Caption = 'clear'
    TabOrder = 1
    OnClick = clearClick
  end
  object a: TEdit
    Left = 18
    Top = 40
    Width = 63
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 2
  end
  object s: TComboBox
    Left = 87
    Top = 40
    Width = 49
    Height = 21
    ItemIndex = 0
    TabOrder = 3
    Text = '+'
    Items.Strings = (
      '+'
      '-'
      '*'
      '/')
  end
  object d: TEdit
    Left = 390
    Top = 40
    Width = 63
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 4
  end
  object c: TEdit
    Left = 266
    Top = 40
    Width = 63
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 5
  end
  object b: TEdit
    Left = 142
    Top = 40
    Width = 63
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 6
  end
  object e: TEdit
    Left = 514
    Top = 40
    Width = 63
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 7
  end
  object s2: TComboBox
    Left = 335
    Top = 40
    Width = 49
    Height = 21
    ItemIndex = 0
    TabOrder = 8
    Text = '+'
    Items.Strings = (
      '+'
      '-'
      '*'
      '/')
  end
  object s1: TComboBox
    Left = 211
    Top = 40
    Width = 49
    Height = 21
    ItemIndex = 0
    TabOrder = 9
    Text = '+'
    Items.Strings = (
      '+'
      '-'
      '*'
      '/')
  end
  object s3: TComboBox
    Left = 459
    Top = 40
    Width = 49
    Height = 21
    ItemIndex = 0
    TabOrder = 10
    Text = '+'
    Items.Strings = (
      '+'
      '-'
      '*'
      '/')
  end
  object r: TEdit
    Left = 160
    Top = 96
    Width = 81
    Height = 21
    TabOrder = 11
  end
  object m: TMemo
    Left = 280
    Top = 96
    Width = 185
    Height = 89
    Lines.Strings = (
      '')
    TabOrder = 12
  end
  object aa: TEdit
    Left = 18
    Top = 13
    Width = 63
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 13
  end
  object p: TEdit
    Left = 87
    Top = 13
    Width = 26
    Height = 21
    MaxLength = 2
    NumbersOnly = True
    TabOrder = 14
    OnChange = pChange
  end
  object bb: TEdit
    Left = 142
    Top = 13
    Width = 63
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 15
  end
  object dd: TEdit
    Left = 390
    Top = 13
    Width = 63
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 16
  end
  object ccc: TEdit
    Left = 266
    Top = 13
    Width = 63
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 17
  end
  object ee: TEdit
    Left = 514
    Top = 13
    Width = 63
    Height = 21
    MaxLength = 5
    NumbersOnly = True
    TabOrder = 18
  end
  object p1: TEdit
    Left = 211
    Top = 13
    Width = 36
    Height = 21
    MaxLength = 2
    NumbersOnly = True
    TabOrder = 19
    OnChange = p1Change
  end
  object p2: TEdit
    Left = 335
    Top = 13
    Width = 32
    Height = 21
    NumbersOnly = True
    TabOrder = 20
    OnChange = p2Change
  end
  object p3: TEdit
    Left = 459
    Top = 13
    Width = 30
    Height = 21
    NumbersOnly = True
    TabOrder = 21
    OnChange = p3Change
  end
  object p4: TEdit
    Left = 583
    Top = 13
    Width = 49
    Height = 21
    NumbersOnly = True
    TabOrder = 22
    OnChange = p4Change
  end
end

object Fcec: TFcec
  Left = 0
  Top = 0
  BorderIcons = [biSystemMenu]
  BorderStyle = bsSingle
  Caption = 'Cecuri Eliberate'
  ClientHeight = 375
  ClientWidth = 786
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  Position = poDesktopCenter
  OnClose = FormClose
  PixelsPerInch = 96
  TextHeight = 13
  object Panel1: TPanel
    Left = 0
    Top = 0
    Width = 786
    Height = 73
    Align = alTop
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 46
      Width = 57
      Height = 13
      Caption = 'De la Data: '
    end
    object Label2: TLabel
      Left = 191
      Top = 46
      Width = 68
      Height = 13
      Caption = 'Pana la Data: '
    end
    object Label3: TLabel
      Left = 16
      Top = 14
      Width = 49
      Height = 13
      Caption = 'Utilizator: '
    end
    object Label4: TLabel
      Left = 64
      Top = 14
      Width = 42
      Height = 13
      Caption = 'Utilizator'
    end
    object Cauta: TSpeedButton
      Left = 384
      Top = 22
      Width = 105
      Height = 45
      Caption = 'CAUTA'
      OnClick = CautaClick
    end
    object SpeedButton1: TSpeedButton
      Left = 495
      Top = 22
      Width = 105
      Height = 45
      Caption = 'Raport CECURI'
      OnClick = SpeedButton1Click
    end
    object SpeedButton2: TSpeedButton
      Left = 606
      Top = 22
      Width = 105
      Height = 45
      Caption = 'Raport PRODUSE'
      OnClick = SpeedButton2Click
    end
    object DT1: TDateTimePicker
      Left = 79
      Top = 38
      Width = 106
      Height = 21
      Date = 44397.000000000000000000
      Time = 0.797034409719344700
      TabOrder = 0
    end
    object DT2: TDateTimePicker
      Left = 263
      Top = 38
      Width = 106
      Height = 21
      Date = 44397.000000000000000000
      Time = 0.797034409719344700
      TabOrder = 1
    end
  end
  object Panel2: TPanel
    Left = 0
    Top = 73
    Width = 786
    Height = 261
    Align = alClient
    TabOrder = 1
    object Panel4: TPanel
      Left = 1
      Top = 130
      Width = 784
      Height = 130
      Align = alBottom
      TabOrder = 0
      object DBGrid1: TDBGrid
        Left = 1
        Top = 1
        Width = 782
        Height = 128
        Align = alClient
        DataSource = dm.dsqvanzare
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
        ReadOnly = True
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
        Columns = <
          item
            Alignment = taCenter
            Expanded = False
            Title.Alignment = taCenter
            Title.Caption = 'Nr.'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Width = 37
            Visible = True
          end
          item
            Alignment = taCenter
            Expanded = False
            FieldName = 'cod'
            Title.Alignment = taCenter
            Title.Caption = 'Cod Produs'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Width = 80
            Visible = True
          end
          item
            Alignment = taCenter
            Expanded = False
            FieldName = 'PRODUS'
            Title.Alignment = taCenter
            Title.Caption = 'Produs'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Width = 141
            Visible = True
          end
          item
            Alignment = taCenter
            Expanded = False
            FieldName = 'CANTITATEA'
            Title.Alignment = taCenter
            Title.Caption = 'Cant.'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Visible = True
          end
          item
            Alignment = taCenter
            Expanded = False
            FieldName = 'PRET_VANZARE'
            Title.Alignment = taCenter
            Title.Caption = 'Cost'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'SUMA'
            Title.Alignment = taCenter
            Title.Caption = 'Suma'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'VALOAREA'
            Title.Alignment = taCenter
            Title.Caption = 'Discount'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'SUMA_DISC'
            Title.Alignment = taCenter
            Title.Caption = 'Suma Discount'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Width = 149
            Visible = True
          end
          item
            Expanded = False
            FieldName = 'SUMA_TOTAL'
            Title.Alignment = taCenter
            Title.Caption = 'Suma Finala'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Width = 81
            Visible = True
          end>
      end
    end
    object Panel5: TPanel
      Left = 1
      Top = 1
      Width = 784
      Height = 129
      Align = alClient
      TabOrder = 1
      object DBGrid2: TDBGrid
        Left = 1
        Top = 1
        Width = 782
        Height = 127
        Align = alClient
        DataSource = dm.dsqcec
        Options = [dgTitles, dgIndicator, dgColumnResize, dgColLines, dgRowLines, dgTabs, dgRowSelect, dgConfirmDelete, dgCancelOnExit, dgTitleClick, dgTitleHotTrack]
        ReadOnly = True
        TabOrder = 0
        TitleFont.Charset = DEFAULT_CHARSET
        TitleFont.Color = clWindowText
        TitleFont.Height = -11
        TitleFont.Name = 'Tahoma'
        TitleFont.Style = []
        OnCellClick = DBGrid2CellClick
        Columns = <
          item
            Alignment = taCenter
            Expanded = False
            Title.Alignment = taCenter
            Title.Caption = 'Nr.'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Width = 37
            Visible = True
          end
          item
            Alignment = taCenter
            Expanded = False
            FieldName = 'NR_CEC'
            Title.Alignment = taCenter
            Title.Caption = 'Nr_Cec'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Width = 68
            Visible = True
          end
          item
            Alignment = taCenter
            Expanded = False
            FieldName = 'DATA_CEC'
            Title.Alignment = taCenter
            Title.Caption = 'Data_Cec'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Width = 95
            Visible = True
          end
          item
            Alignment = taCenter
            Expanded = False
            FieldName = 'SUMA_CEC'
            Title.Alignment = taCenter
            Title.Caption = 'Suma_cec'
            Title.Font.Charset = DEFAULT_CHARSET
            Title.Font.Color = clWindowText
            Title.Font.Height = -11
            Title.Font.Name = 'Tahoma'
            Title.Font.Style = [fsBold]
            Width = 76
            Visible = True
          end>
      end
    end
  end
  object Panel3: TPanel
    Left = 0
    Top = 334
    Width = 786
    Height = 41
    Align = alBottom
    TabOrder = 2
    object Label5: TLabel
      Left = 2
      Top = 16
      Width = 48
      Height = 16
      Caption = 'TOTAL: '
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label6: TLabel
      Left = 64
      Top = 16
      Width = 32
      Height = 16
      Alignment = taRightJustify
      Caption = '0.000'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
    object Label7: TLabel
      Left = 102
      Top = 16
      Width = 16
      Height = 16
      Alignment = taRightJustify
      Caption = 'Lei'
      Font.Charset = DEFAULT_CHARSET
      Font.Color = clWindowText
      Font.Height = -13
      Font.Name = 'Tahoma'
      Font.Style = []
      ParentFont = False
    end
  end
end